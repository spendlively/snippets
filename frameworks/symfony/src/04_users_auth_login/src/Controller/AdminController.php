<?php

namespace App\Controller;


use App\Entity\Role;
use App\Entity\User;
use App\Service\UserServiceInterface;
use Doctrine\Bundle\DoctrineBundle\Registry;
use Doctrine\ORM\EntityManagerInterface;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\Form\Extension\Core\Type\ChoiceType;
use Symfony\Component\Form\Extension\Core\Type\EmailType;
use Symfony\Component\Form\Extension\Core\Type\PasswordType;
use Symfony\Component\Form\Extension\Core\Type\SubmitType;
use Symfony\Component\Form\Extension\Core\Type\TextareaType;
use Symfony\Component\Form\Extension\Core\Type\TextType;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\Routing\Annotation\Route;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\IsGranted;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Security\Core\Encoder\UserPasswordEncoderInterface;

class AdminController extends AbstractController
{
    /**
     * @IsGranted("ROLE_ADMIN")
     * @Route("/admin/", name="admin")
     * @return Response
     */
    public function admin()
    {
        return $this->render('admin/admin.html.twig', [
        ]);
    }

    /**
     * @IsGranted("ROLE_ADMIN")
     * @Route("/admin/user/list", name="admin_users")
     * @param UserServiceInterface $userService
     * @return Response
     */
    public function users(UserServiceInterface $userService)
    {
        return $this->render('admin/users.html.twig', [
            'users' => $userService->getAllUsers(),
        ]);
    }


    /**
     * @IsGranted("ROLE_ADMIN")
     * @Route("/admin/user/add", name="admin_add_user")
     * @param Request $request
     * @param UserServiceInterface $userService
     * @param UserPasswordEncoderInterface $encoder
     * @return Response
     */
    public function addUser(Request $request, UserServiceInterface $userService, UserPasswordEncoderInterface $encoder)
    {
        $user = new User();
        $form = $this->createFormBuilder($user)
            ->add('username', TextType::class, ['label' => 'Username: '])
            ->add('lastname', TextType::class, ['label' => 'Lastname: ', 'required' => false])
            ->add('password', PasswordType::class, ['label' => 'Password: '])
            ->add('email', EmailType::class, ['label' => 'Email: '])
            ->add('description', TextareaType::class, ['required' => false, 'label' => 'Description: '])
            ->add('roles', ChoiceType::class, [
                'label' => 'Role: ',
                'choices' => Role::getRoles(),
                'multiple' => true,
            ])
            ->add('add', SubmitType::class, ['label' => 'Create User'])
            ->getForm();

        $form->handleRequest($request);
        if ($form->isSubmitted()) {

            $user = $form->getData();
            $user->setPassword($encoder->encodePassword($user, $user->getPassword()));
            $userService->addUser($user);

            return $this->redirectToRoute('admin_users');
        }

        return $this->render('admin/add_user.html.twig', [
            'form' => $form->createView(),
        ]);
    }

    /**
     * @IsGranted("ROLE_ADMIN")
     * @Route("/admin/user/{id}/edit", name="admin_edit_user")
     * @param $id
     * @param Request $request
     * @param UserServiceInterface $userService
     * @param UserPasswordEncoderInterface $encoder
     * @return Response
     */
    public function editUser($id, Request $request, UserServiceInterface $userService, UserPasswordEncoderInterface $encoder)
    {
        $user = $userService->getUserById((int)$id);
        $password = $user->getPassword();

        $form = $this->createFormBuilder($user)
            ->add('username', TextType::class, ['label' => 'Username: '])
            ->add('lastname', TextType::class, ['label' => 'Lastname: ', 'required' => false])
            ->add('password', PasswordType::class, ['label' => 'Password: ', 'required' => false])
            ->add('email', EmailType::class, ['label' => 'Email: '])
            ->add('description', TextareaType::class, ['required' => false, 'label' => 'Description: '])
            ->add('roles', ChoiceType::class, [
                'label' => 'Role: ',
                'choices' => Role::getRoles(),
                'multiple' => true,
            ])
            ->add('add', SubmitType::class, ['label' => 'Edit User'])
            ->getForm();

        $form->handleRequest($request);
        if ($form->isSubmitted()) {

            $user = $form->getData();

            if ($user->getPassword() === null) {
                $user->setPassword($password);
            } else {
                $user->setPassword($encoder->encodePassword($user, $user->getPassword()));
            }

            $userService->addUser($user);
            return $this->redirectToRoute('admin_users');
        }

        return $this->render('admin/edit_user.html.twig', [
            'form' => $form->createView(),
        ]);
    }

    /**
     * @IsGranted("ROLE_ADMIN")
     * @Route("/admin/user/delete", name="admin_delete_user")
     * @param Request $request
     * @param UserServiceInterface $userService
     * @return Response
     * @throws \Exception
     */
    public function deleteUser(Request $request, UserServiceInterface $userService)
    {
        $id = $request->get('id');
        if ($id === null) {
            throw new \Exception('User id must be specified');
        }

        $user = $userService->getUserById((int)$id);
        $currentUser = $this->getUser();

        if ($user->getId() === $currentUser->getId()) {
            throw new \Exception('You can not delete yourself');
        }

        $userService->deleteUser($user);

        return $this->redirectToRoute('admin_users');
    }
}
